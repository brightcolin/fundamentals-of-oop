# Assignment 10 — DynArray (RAII / Move Semantics)

> 移动语义与RAII | 面向对象程序设计基础 第 10 次作业

---

## 📌 Description

Three complementary components that demonstrate move semantics and smart-pointer trade-offs:

1. **`CP_DynArray<T>`** — a move-only RAII wrapper around a raw pointer (copy explicitly deleted).
2. **`CP_DListRaw<T>`** — a doubly-linked list using raw `new`/`delete`.
3. **`CP_DListSmart<T>`** — the same doubly-linked list using `shared_ptr` + `weak_ptr` (no manual `delete`).

`CP_A` is an instrumented helper class that prints every constructor and destructor call, making ownership transfer visible at runtime.

---

## 📁 File Structure

```
assignment10/
├── CP_DynArray.h            # Move-only RAII wrapper (copy = delete)
├── CP_A.h                   # Instrumented demo class (ctor/dtor prints)
├── CP_DListRaw.h            # Doubly-linked list — raw pointer (header-only template)
├── CP_DListSmart.h          # Doubly-linked list — shared_ptr/weak_ptr (header-only template)
├── CP_DynArrayTest.h        # Test class header
├── CP_DynArrayTest.cpp      # Tests for DynArray + DListRaw + DListSmart
├── CP_DynArrayTestMain.cpp  # Entry point: automated tests
└── CP_DynArrayBenchmark.cpp # Entry point: raw vs smart pointer push/pop benchmark
```

---

## 🏗️ Class Designs

### CP_DynArray\<T\> (move-only)

| Special member | Rule |
|----------------|------|
| Default ctor | `m_data = nullptr` |
| Pointer ctor | Takes ownership of `T*` |
| Move ctor | Transfers `m_data`, sets source to `nullptr` |
| Move assignment | Releases old, takes source's pointer |
| Copy ctor / assign | `= delete` |
| Destructor | `delete m_data` if non-null |

### CP_DListRaw\<T\> vs CP_DListSmart\<T\>

Both expose the same API (`mb_pushFront`, `mb_pushBack`, `mb_popFront`, `mb_popBack`, `mb_show`, `mb_showReverse`). The key difference:

| | CP_DListRaw | CP_DListSmart |
|-|-------------|---------------|
| Node memory | raw `new`/`delete` | `shared_ptr<Node>` |
| Back pointer | raw `Node*` | `weak_ptr<Node>` (avoids cycle) |
| Manual delete | required in dtor | not needed |

`weak_ptr` for the back pointer prevents the reference-count cycle that would otherwise cause a memory leak in a doubly-linked list using only `shared_ptr`.

---

## 🧪 Test Groups

| Method | What is tested |
|--------|----------------|
| `mb_testDefaultCtor` | Null state after default construction |
| `mb_testPtrCtor` | Ownership transfer from raw pointer |
| `mb_testMoveCtor` | Source becomes null after move |
| `mb_testMoveAssign` | Old resource released, new ownership transferred |
| `mb_testGet` | `mb_get()` returns correct pointer |
| `mb_testSwap` | Pointer swap without ownership loss |
| `mb_testWithCPA` | CP_A ctor/dtor visible in output |
| `mb_testDListRaw` | pushFront/Back, popFront/Back, size |
| `mb_testDListSmart` | same operations via shared_ptr version |

---

## 🚀 How to Compile & Run

```bash
# Automated tests
g++ -std=c++11 CP_DynArrayTestMain.cpp CP_DynArrayTest.cpp -o test
.\test.exe

# Raw vs smart pointer benchmark
g++ -std=c++11 -O2 CP_DynArrayBenchmark.cpp -o benchmark
.\benchmark.exe
```

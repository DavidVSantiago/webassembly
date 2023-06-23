(module
  (type (;0;) (func))
  (type (;1;) (func (param i32) (result i32)))
  (import "env" "__memory_base" (global (;0;) i32))
  (import "env" "__table_base" (global (;1;) i32))
  (import "env" "memory" (memory (;0;) 0))
  (func (;0;) (type 0)
    call 1)
  (func (;1;) (type 0))
  (func (;2;) (type 1) (param i32) (result i32)
    local.get 0
    i32.const 1
    i32.add)
  (export "__wasm_call_ctors" (func 0))
  (export "increment" (func 2)))

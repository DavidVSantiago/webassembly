// recupera os bites do modulo binário "module"
const wasmInstance = new WebAssembly.Instance(module, {});
const { addTwo } = wasmInstance.exports;
for (let i = 0; i < 10; i++) {
  console.log(addTwo(i, i));
}

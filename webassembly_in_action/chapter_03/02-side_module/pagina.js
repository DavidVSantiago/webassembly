// objeto passado como 2 par. p/ o módulo webassembly (modelo padrão)
const importObject = { 
    env: { 
      __memory_base:0,
      __table_base:0,
      'memory':new WebAssembly.Memory({initial:1}),
    } 
  };

// faz a requisição assíncrona no módulo webassembly
const module = fetch("side-module.wasm");

// faz a compilação e instanciação do modulo, ao passo que é baixado.
WebAssembly.instantiateStreaming(module,importObject)
.then(result => { // ao término bem sucedido
    const valor = result.instance.exports.increment(15);
    console.log(valor.toString());
});


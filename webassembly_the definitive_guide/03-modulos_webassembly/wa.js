function fetchAndInstantiate(url, funcaoExterna){
    return fetch(url).then(response=>
        response.arrayBuffer()
    ).then(bytes =>
        WebAssembly.instantiate(bytes, funcaoExterna)
    ).then(results =>
        results.instance
    );
}
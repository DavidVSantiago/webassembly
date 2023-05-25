(module
    ;; importa uma função host que espera um único parâmetro
    (func $func_importada (import "imports" "func_importada")(param i32))

    (func $idade (param $ano_atual i32) (param $ano_nasc i32) (result i32)
        local.get $ano_atual ;; empilha o param "ano_atual" 
        local.get $ano_nasc ;; empilha o param "ano_nasc"
        i32.sub ;; desempilha 2 valores, subtrai-os e empilha o resultado
    )
    (func $long_idade (param $ano_atual i32) (param $ano_nasc i32)
        local.get $ano_atual ;; empilha o param "ano_atual" 
        local.get $ano_nasc ;; empilha o param "ano_nasc"
        call $idade
        call $func_importada
    )

  	(export "idade" (func $idade)) ;; exporta  afunção para ser usada externamente
    (export "long_idade" (func $long_idade)) ;; exporta  afunção para ser usada externamente

)
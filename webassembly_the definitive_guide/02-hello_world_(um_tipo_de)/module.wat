(module
    (func $idade (param $ano_atual i32) (param $ano_nasc i32) (result i32)
        local.get $ano_atual ;; empilha o param "ano_atual" 
        local.get $ano_nasc ;; empilha o param "ano_nasc"
        i32.sub ;; desempilha 2 valores, subtrai-os e empilha o resultado
    )
  	(export "idade" (func $idade)) ;; exporta  afunção para ser usada externamente
)
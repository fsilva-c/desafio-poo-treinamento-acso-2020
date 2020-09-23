# Acso City

[![Build Status](https://travis-ci.org/joemccann/dillinger.svg?branch=master)](https://travis-ci.org/joemccann/dillinger)

Acso city é uma cidade que foi afetada por um virus mortal! Descubra atravéz da simulação o que acontecerá em x anos.

  - A cidade é feita em uma matriz de 10x10
  - Uma pessoa do sexo feminino pode gerar uma nova pessoa. Para isso ela deve estar em contato com uma pessoa do sexo masculino e devem ter entre 18 e 25 anos
  - Uma pessoa envelhece com o passar dos anos
  - Entre 3 e 8 anos, se a pessoa estiver sadia ela pode tomar a vacina para não ser infectada
  - Uma pessoa doente pode infectar outras pessoas. A transmissão da doença é feita para todas as pessoas que estiverem em contato com ela, que ainda não tenham sido vacinadas
  - Uma pessoa morre por dois motivos: quando atinge os 30 anos ou quando está infectada a mais de dois anos

### Executar o sistema 

```sh
$ make
$ acso-city/binaries/./desafio 
```
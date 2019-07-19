**Profiling**

  Comencé con el programa `1-loop-interch.f90`. En este programa recorre una matriz mediante un loop anidado de dos formas distintas.
En primer lugar recorre primero las columnas y luego las filas, y en segundo lugar invierte el orden. Usando `time` y corriendo el programa compilando con las distintas optimizaciones obtengo los tiempos:

  `-O0`: 3.20 s
  `-O1`: 2.79 s
  `-O2`: 2.91 s
  `-O3`: 0.84 s

  Luego, para hacer el *profiling* use gprof. Para usarlo, compilé con los flags `-pg -O0`, siendo el -pg un flag que crea un archivo que permite el profile ('gmon.out'). cuando corro `gprof ./1-loop-interch.p90`, devuelve:

  ```
...
  %   cumulative   self              self     total
 time   seconds   seconds    calls   s/call   s/call  name
100.21      3.55     3.55        1     3.55     3.55  MAIN__
...
```

  Para ver el tiempo linea-a-linea agrego un flag, `gprof ./1-loop-interch.p90`:

  ```
  %   cumulative   self              self     total           
 time   seconds   seconds    calls  Ts/call  Ts/call  name    
 79.80      2.80     2.80                             MAIN__ (1-loop-interch.f90:58 @ 40153e)
 10.99      3.19     0.39                             MAIN__ (1-loop-interch.f90:38 @ 401179)
  2.28      3.27     0.08                             MAIN__ (1-loop-interch.f90:29 @ 40107d)
  2.00      3.34     0.07                             MAIN__ (1-loop-interch.f90:27 @ 400fd3)
  1.71      3.40     0.06                             MAIN__ (1-loop-interch.f90:28 @ 40101d)
  0.86      3.43     0.03                             MAIN__ (1-loop-interch.f90:50 @ 401442)
  0.71      3.45     0.03                             MAIN__ (1-loop-interch.f90:57 @ 401603)
  0.57      3.47     0.02                             MAIN__ (1-loop-interch.f90:48 @ 401398)
  0.57      3.49     0.02                             MAIN__ (1-loop-interch.f90:49 @ 4013e2)
  0.43      3.51     0.02                             MAIN__ (1-loop-interch.f90:37 @ 401166)
  0.29      3.52     0.01                             MAIN__ (1-loop-interch.f90:57 @ 40152b)
  0.00      3.52     0.00        1     0.00     0.00  MAIN__ (1-loop-interch.f90:1 @ 400b16)
```

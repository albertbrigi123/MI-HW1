# MI-HW1

Huszárvándorlás-probléma (Sakktábla bejárása lóugrással)

A huszárvándorlás-probléma, huszárkörút vagy sakktábla bejárása huszárral egy huszár lépéssorozata a sakktáblán, amely alatt a huszár a tábla minden mezőjét pontosan egyszer érinti.
https://hu.wikipedia.org/wiki/Husz%C3%A1rv%C3%A1ndorl%C3%A1s-probl%C3%A9ma

A program futtatása során meg kell adni az n értékét ami a sakktábla méretét jelképezni. 4x4-esnél kisebb sakktábla esetén a feladat nem működik. A feladat második paramétereként megkell adni az opciót, hogy melyik megoldási módszerrel szeretnénk lefuttatni.
1. nyers backtracking
2. backtracking + MVR + forward checking
3. backtracking + MVR + AC-3

Ha n=8 és az 1-es a választott opció, akkor a bejárás eredménye:
0 59 38 33 30 17 8 63
37 34 31 60 9 62 29 16
58 1 36 39 32 27 18 7
35 48 41 26 61 10 15 28
42 57 2 49 40 23 6 19
47 50 45 54 25 20 11 14
56 43 52 3 22 13 24 5
51 46 55 44 53 4 21 12

Az értékadások száma: 8250732

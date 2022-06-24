Napisz program ktory oblicza BER (Bit Error Rate) dla dwóch dowolnych plików.

Swoj¹ pracê utrzymaj na repozytorium na github. 

Twoja praca musi byæ udokumentowana przez kolejne commity.



Wymagania dla programu :



1. Program konsolowy. Jako dwa argumenty przyjmuje œcie¿ki do plików dla których oblicza wartoœæ BER.

2. Wynik obliczeñ drukowany jest w konsoli (Jako wynik podajemy: Iloœæ porównanych bitów, iloœæ ró¿nych bitów, wynik BER, czas obliczeñ)

3. Program tworzy plik log.txt w którym zapisuje swoje logi. Ka¿da wiadomoœæ rozpoczyna siê od timestamp'a.

4. Test 1: Przygotuj dwa identyczne pliki zawieraj¹ce binarnie zapisan¹ wartoœæ 0x55. Ka¿dy plik po 100 Bajtów. 

5. Test 2: Przygotuj dwa pliki ka¿dy po 100 bajtów. Pierwszy zawiera binarnie zapisan¹ wartoœæ 0x55. Drugi plik ró¿ni siê od pierwszego o dowolne 10 bitów.

6. Test 3: Przygotuje dwa pliki ka¿dy po 400 MB. Pierwszy zawiera binarnie zapisan¹ wartoœæ 0x55. Drugi plik zawiera binarnie zapisan¹ wartoœæ 0x50.



Podaj wynik dzia³ania programu BER dla podanych plików testowych (Wyniki zapisane w pliku z logami) 
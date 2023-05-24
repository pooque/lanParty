Aceasta solutie automatizeaza un LAN Party. Fiecare cerinta este executata de functiile "task" cu numarul de ordine corespunzator.

Cerinta 1 - creare lista (definitii in player.c)
In cadrul acestei cerinte, functia "create_list_ofTeams" preia informatiile din fisierul d.in pentru a genera o lista a echipelor participante.
Folosind datele furnizate in fisier, urmatoarele functii opereaza pe date referitoare la echipa si/sau membrii acesteia:
- read_n_ofPlayers      : citeste numarul de echipe inscrise
- read_name_ofTeam      : citeste numele echipei
- read_dataAboutPlayer  : citeste datele de identificare ale jucatorilor (nume, prenume, punctaj)
Considerand prima echipa inscrisa ca inceput de lista, restul echipelor vor fi adaugate folosind functia "enter_Teams". 
Aditional, functia "AVG_score" (definita in points.c) determina scorul general al echipei curente.

Cerinta 2 - eliminare echipe (definitii in points.c)
Odata cu inscrierea echipelor, se efectueaza stergerea echipelor cu scor de echipa minim. Se foloseste functia "purge_Teams" pentru acest proces.
Stergerea s-a efectuat pana la obtinerea unui numar de echipe egal cu un 2^k maxim (mai mic decat numarul initial).
Functii folosite:
- min_Score         : determina scorul minim de echipa (pentru pasul curent)
- AVG_score         : determina media scorului per echipa
- find_N_max        : gaseste 2^k maxim
- delete_firstTeam  : stergere prima echipa cu scor minim
- delete_Team       : stergere echipe cu scor minim
!!! Presupunem situatia unui numar de echipe consecutive in situatie de eliminare. Functia "purge_Teams" acopera acest caz. !!!

Cerinta 3 - meciuri + winners/losers (definitii in 1v1.c pentru meciuri, in winners_losers.c pentru rezultatul rundelor, in top8.c pentru top)
Meciurile se organizeaza intre echipele ramase. Fiecare runda va determina castigatorii ("winners"), iar invinsii ("losers") vor fi eliminati.
Dupa fiecare runda, punctajul echipei castigatoare va creste cu 1 punct.
Fiecare runda va contine meciuri stabilite intre castigatorii anteriori, pana la determinarea echipei cu scor maxim.
Castigatorii si invinsii sunt salvati in stive dedicate, iar meciurile intr-o coada. Se realizeaza un top al celor 8 echipe ramase.
Avem in vedere functiile:
- set_Matches   : opereaza lista de echipe, construind o coada de meciuri (functia "makePair" creeaza perechi de echipe)
- purge_Matches : automatizeaza rundele LAN Party-ului
    - create_Stack          : umple stivele cu winners si losers (functiile "add_toWhich" si "add_toStack" populeaza corespunzator stivele)
    - set_Matches_fromStack : formeaza meciuri intre castigatorii precedenti (functia "makePair_fromStack" creeaza echipe din stiva)
    - addTo_top8            : creeaza topul celor 8 echipe ramase

Cerinta 4 - BST (definitii in BST.c)
Topul se va salva intr-o structura de arbore BST. Se realizeaza sortarea in functie de punctaj, si afisarea in ordine descrescatoare.
Functia "create_BST" genereaza arborele, apeland functiile urmatoare:
- add_toTree : prin apel recursiv, functia parcurge in adancime arborele, urmand ca functia
- add_toLeaf : realizeaza adaugarea propriu-zisa
    !!! S-a luat in considerare situatia echipelor cu scor egal. Se prioritizeaza numele echipei. !!!

Cerinta 5 - AVL (definitii in AVL.c)
Arborelui BST i se aplica echilibrarea de tip AVL, afisandu-se echipele de pe nivelul 2 al arborelui.
- add_BST_toList    : prin apel recursiv, se genereaza o lista a echipelor din BST
- add_toList        : executa inserarea in lista
- findAt_m          : returneaza pointer-ul catre echipa de pe pozitia m (numarul de ordine in lista a nodurilor de pe nivelul 2 in AVL)

Solutia este optima intrucat implementarea structurilor se face dinamic, cu eliberarile de memorie necesare.
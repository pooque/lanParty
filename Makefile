build:
	gcc main.c 1v1.c allMain.c BST.c player.c points.c top8.c winners_losers.c AVL.c -o lanParty
clean:
	rm -f lanParty
run:
	./lanParty c.in d.in r.out
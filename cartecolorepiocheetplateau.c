
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>

typedef struct t_tuile
{
  int couleur;
  char forme;
} t_tuile;


void cartecoloremain(t_tuile main[6], int tailledelamain)
{ int i;
  for (i=0; i<tailledelamain; i++)
   { if (main[i].couleur==0)
        { Color(12,0);
          printf("%d%c ",main[i].couleur, main[i].forme);
        }
      if (main[i].couleur==1)
        { Color(11,0);
          printf("%d%c ",main[i].couleur, main[i].forme);
        }
      if (main[i].couleur==2)
        { Color(13,0);
          printf("%d%c ",main[i].couleur, main[i].forme);
        }
      if (main[i].couleur==3)
        { Color(10,0);
          printf("%d%c ",main[i].couleur, main[i].forme);
        }
      if (main[i].couleur==4)
        { Color(14,0);
          printf("%d%c ",main[i].couleur, main[i].forme);
        }
       if (main[i].couleur==5)
        { Color(7,0);
          printf("%d%c ",main[i].couleur, main[i].forme);
        }
   }

Color(15,0);
}


void cartecoloreplateau(t_tuile plateau[12][26], int i, int j)
{   if (plateau[i][j].couleur==0)
        { Color(12,0);
          printf("%c ", plateau[i][j].forme);
        }
      if (plateau[i][j].couleur==1)
        { Color(11,0);
          printf("%c ", plateau[i][j].forme);
        }
      if (plateau[i][j].couleur==2)
        { Color(13,0);
          printf("%c ", plateau[i][j].forme);
        }
      if (plateau[i][j].couleur==3)
        { Color(10,0);
          printf("%c ", plateau[i][j].forme);
        }
      if (plateau[i][j].couleur==4)
        { Color(14,0);
          printf("%c ", plateau[i][j].forme);
        }
       if (plateau[i][j].couleur==5)
        { Color(7,0);
          printf("%c ", plateau[i][j].forme);
        }

Color(15,0);

}

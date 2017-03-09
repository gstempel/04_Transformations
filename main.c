#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"
#include "matrix.h"
#include "parser.h"

int main(int argc, char **argv) {

  screen s;
  struct matrix * edges;
  struct matrix * transform;
  
  edges = new_matrix(4, 4);
  transform = new_matrix(4, 4);

  //============TESTING DEGTORAD FUNCTION==============
  printf("0 deg = %f\n", degToRad(0));
  printf("180 deg = %f\n", degToRad(180));
  printf("360 deg = %f\n", degToRad(360));

  //============TESTING TRANSFORMATION FUNCTIONS==============
  transform = make_translate(50, 50, 50);
  transform = make_scale(5, 4, 3);
  transform = make_rotX(90);
  transform = make_rotY(180);
  transform = make_rotZ(270);

  ident(transform);

  if ( argc == 2 )
    parse_file( argv[1], transform, edges, s );
  else
    parse_file( "stdin", transform, edges, s );

  
  free_matrix( edges );
  free_matrix( transform );
}  

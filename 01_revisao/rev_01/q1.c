#include <stdio.h>
#include <math.h>

int main() {
  float xA=0, yA=0, rA=0, xD=0, yD=0, rD=0, soma=0, dist=0;
  scanf("%f %f %f", &xA, &yA, &rA);
  scanf("%f %f %f", &xD, &yD, &rD);

  soma = rA + rD;
  dist = sqrt(pow(xA-xD, 2) + pow(yA-yD, 2));

  if(dist <= soma){
    printf("ACERTOU");
  }
  else {
    printf("ERROU");
  }
  
  return 0;
}

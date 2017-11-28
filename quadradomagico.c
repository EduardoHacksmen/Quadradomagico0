//Eduardo Ferreira Leite RGA 201719040486
//obs: caso n for igual 2 n achei solução para fazer um quadrado magico
#include <stdio.h>
#include <string.h>
#define max 100

void imprimeM(int n, int m[][max])//Função para imprimir matriz
{
    int i, j;
    
    for(i=0; i<n; i++){
	    for(j=0; j<n; j++){
	        printf("%5d",m[i][j]);
	    }
	    printf("\n");
	}  
}

int main(){
    //Declarações iniciais
	int m[max][max], i, j, n, a=1;
	int matriz[max][max]={0}, h;

	scanf("%d", &n);
	if(!(n%2==0))//Caso 1: n ´ımpar
	{
      h=(n*n);
      i=0;
      j=n/2;
      while(h>0){
        matriz[i][j]=a;
        if(i==0){
            i=(n-1);
        }
        else{
            i--;
        }
        if(j==(n-1)){
            j=0;
        }
        else{
            j++;
        }
        if(matriz[i][j]!=0){
            i+=2;
            j--;
            if(i>(n-1)){
                i-=n;
            }
            if(j<0){
                j+=n;
            }
            }
        h--;
        a++;
    
        }
    imprimeM(n, matriz);
    }
	else if(n%4==0)// Caso 2: n = 4m para m ≥ 1
	{
	    int m1[max][max]={0}, m2[max][max], m3[max][max], m4[max][max]={0};//observe que criei outros 4 vetores 
	    int inv, iqu, aux;
	    
		for(i=0; i<n; i++)//preencho o vetor 
		{
		   for(j=0; j<n; j++){
			  m[i][j]=a;
			  a++;
		   }
	   }
	   //prencho o a matriz m1
	   for(i=0; i<n/2; i++){
		  for(j=0; j<n/2; j++){
             if(!(i-j)){
               m1[i][j]=m[i][j];
             }
             if(i+j== (n/2)-1){
         	   m1[i][j]=m[i][j];
             }
          
		  }
       }
       //inverto a matriz m1
	    inv=(n/2)-1;
	    for(i=0; i<n/4; i++){
	       for(j=0; j<n/4; j++){
	           if(i==j){
	             aux=m1[i][j];
	             m1[i][j]=m1[inv][inv];
	             m1[inv][inv]=aux;
	             inv--;
	           }
	       }
	    }
	    for(i=0; i<n/4; i++){
	       for(j=1; j<n/2; j++){
	          if(i+j==(n/2)-1){
	             aux=m1[i][j];
	             m1[i][j]=m1[j][i];
	             m1[j][i]=aux;
	          }
	       }
	    }
	    //prencho a matriz m2
        for(i=0; i<n/2; i++){
           for(j=n/2; j<n; j++){
              if(n-1==i+j){
                m2[i][j-n/2]=m[i][j];
              }
              if(j==(n/2)+i){
                m2[i][j-n/2]=m[i][j];
              }
           }
        }
        //inverto a matriz m2 
	    inv=(n/2)-1;
	    for(i=0; i<n/4; i++){
	       for(j=0; j<n/4; j++){
	          if(i==j){
	            aux=m2[i][j];
	            m2[i][j]=m2[inv][inv];
	            m2[inv][inv]=aux;
	            inv--;
	          }
	       }
	    }
	     //prencho a matriz m3
	    for(i=n/2; i<n; i++){
	       for(j=0; j<n/2; j++){
	          if(j+n/2==i)
	          {
	            m3[i-n/2][j]=m[i][j];
	          }
	          if(j+i==n-1)
	          {
	            m3[i-n/2][j]=m[i][j]; 
	          }
	       }
	    }
	 //inverto a matriz m3    
	inv=(n/2)-1;
	for(i=0; i<n/4; i++){
	    for(j=0; j<n/4; j++){
	        if(i==j)
	        {
	            aux=m3[i][j];
	            m3[i][j]=m3[inv][inv];
	            m3[inv][inv]=aux;
	            inv--;
	        }
	    }
	}
	for(i=0; i<n/4; i++){
	    for(j=1; j<n/2; j++){
	        if(i+j==(n/2)-1)
	        {
	         aux=m3[i][j];
	         m3[i][j]=m3[j][i];
	         m3[j][i]=aux;
	        }
	    }
	}
	 //prencho a matriz m4
	for(i=n/2; i<n; i++){
	    for(j=n/2; j<n; j++){
	      if(!(i-j))
	      {
         	m4[i-n/2][j-n/2]=m[i][j];
          }
          if(11==i+j)
          {
            m4[i-n/2][j-n/2]=m[i][j];  
          }
	    }
	}
	//inverto a matriz m4
	inv=(n/2)-1;
	for(i=0; i<n/4; i++){
	    for(j=0; j<n/4; j++){
	        if(i==j)
	        {
	            aux=m4[i][j];
	            m4[i][j]=m4[inv][inv];
	            m4[inv][inv]=aux;
	            inv--;
	        }
	    }
	}
	for(i=0; i<n/4; i++){
	    for(j=1; j<n/2; j++){
	        if(i+j==(n/2)-1)
	        {
	          aux=m4[i][j];
	          m4[i][j]=m4[j][i];
	          m4[j][i]=aux;
	        }
	    }
	}
	for(i=0; i<n/4; i++){
	    for(j=1; j<n/2; j++){
	        if(i+j==(n/2)-1)
	        {
	          aux=m2[i][j];
	          m2[i][j]=m2[j][i];
	          m2[j][i]=aux;
	        }
	    }
	}
	//agora com as matrizes prontas eu apenas substituo os valores na minha matriz m
    for(i=n/2; i<n; i++){
	    for(j=n/2; j<n; j++){
	        if(i==j)
	        {
	          m[i][j]=m1[i-n/2][j-n/2];
	        }
	        if(i+j==n+(n/2)-1)
	        {
	          m[i][j]=m1[i-n/2][j-n/2];
	        }
	    }
	}
    for(i=n/2; i<n; i++){
        for(j=0; j<n/2; j++){
            if(n-1==i+j)
            {
                m[i][j]=m2[i-n/2][j];
            }
            if(i==(n/2)+j)
            {
                m[i][j]=m2[i-n/2][j];
            }
        }
    }
    for(i=0; i<n/2; i++){
        for(j=n/2; j<n; j++){
            if(n-1==i+j)
            {
                m[i][j]=m3[i][j-n/2];
            }
            if(j==(n/2)+i)
            {
                m[i][j]=m3[i][j-n/2];
            }
        }
    }
    for(i=0; i<n/2; i++){
	    for(j=0; j<n/2; j++){
	        if(m4[i][j]!=0)
	        {
	          m[i][j]=m4[i][j];
	        }
	    }
	}
    imprimeM(n, m);
  }
  else//Caso 3: n = 4m + 2 para m ≥ 1
  { 
    int m12, contl, contv, contx, aux1[max][max]={0}, aux2, x, y;
    
  	m12=(n-2)/4;
	contl=m12+1;
	contv=1;
	contx=m12-1;
	
	for(i=0; i<(2*m12 + 1); i++){
		for(j=0; j<(2*m12 + 1); j++){
			if(contl!=0)
			{
			  aux1[i][j]='L';
			}
			else if(contv!=0)
			{
			       aux1[i][j]='U';
			}
			else if(contx!=0)
			{
				   aux1[i][j]='X';
			}
		}
		if(contl!=0)
		{
		  contl--;
		}
		else if(contv!=0)
		{
			   contv--;
		}
		else if(contx!=0)
		{
			   contx--;
		}
	}
	for(i=0; i<(2*m12 + 1); i++){
		for(j=0; j<(2*m12 + 1); j++){
			if(i==m12&&j==m12)
			{
			  aux2=aux1[i][j];
			  aux1[i][j]=aux1[i+1][j];
			  aux1[i+1][j]=aux2;
			}
		}
	}
	//Cria a matriz auxiliar
	int s;
	
	s=(2*m12+1);
	h=s*s;
	i=0;
	j=s/2;
	
	while(h>0){
	     if(aux1[i][j]=='L')//Caso for L
	     {
	       x=i*2;
	       y=j*2;
	       m[x][y+1]=a;
	       a++;
	       m[x+1][y]=a;
	       a++;
	       m[x+1][y+1]=a;
	       a++;
	       m[x][y]=a;
	       a++;
	     }
	     else if(aux1[i][j]=='U')//Caso for U
	     {
	            x=i*2;
	            y=j*2;
	            m[x][y]=a;
	            a++;
	            m[x+1][y]=a;
	            a++;
	            m[x+1][y+1]=a;
	            a++;
	            m[x][y+1]=a;
	            a++;
	    }
	    else if(aux1[i][j]=='X')//Caso for X
	    {
	           x=i*2;
	           y=j*2;
	           m[x][y]=a;
	           a++;
	           m[x+1][y+1]=a;
	           a++;
	           m[x+1][y]=a;
	           a++;
	           m[x][y+1]=a;
	           a++;
	    }
        aux1[i][j]=1;//aux1[i][j]=1 para que possamos verificar se a posição está prenchida
        if(i==0)
        {
          i=(s-1);
        }
        else
        {
            i--;
        }
        if(j==(s-1))
        {
          j=0;
        }
        else
        {
            j++;
        }
        if(aux1[i][j]!='L'&&aux1[i][j]!='U'&&aux1[i][j]!='X')
        {
          i+=2;
          j--;
          if(i>(s-1))
          {
            i-=s;
          }
          if(j<0)
          {
            j+=s;
            }
        }
        h--;
	    }
	imprimeM(n, m);
  }
	return 0;
}

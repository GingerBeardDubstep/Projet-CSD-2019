#include <arbre.h>

int comparaison(film* source, film* destination){
	int val1=strlen(source->titre);
	int val2=strlen(destination->titre);
	int min;

	if(val1>val2){
		min=val2;
	}else{
		min=val1;
	}

	for(int i=0;i<min;i++){
		if(source->titre[i]>destination->titre[i]){
			return 2;
		}else if(source->titre[i]<destination->titre[i]){
			return 1;
		}
	}
	if(val1>val2){
		return 2;
	}else if(val2>val1){
		return 1;
	}else if(val1==val2){
		return 0;
	}
}
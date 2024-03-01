int a = 200;
int b = 6;
int c;

int i =0;
long* malware_ptr;
long* long_ptr;


void malware(void){
	c = a + b + 2;
}

void victim_function(void){
	c = a + b ;
}

int main(int argc, char** argv){
    char buffer[48];
    long_ptr = (long*) (buffer);
    malware_ptr = (long*) (&malware);
    
    victim_function();

    for (i = 0; i < 16; i = i+1){
        long_ptr[i] = (long) (malware_ptr);

    }

    i = i + 5;
    return 0;
}



template <typename T> 
function(T &t){
    t.print()
}

class myclass{
public:
	void print(){
		printf("xxxxxxxxxxxxxxxxxxx");
	}
};

int main(){
	myclass myc;
	function(myc);
}
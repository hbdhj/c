class function{
public:
	function():x(0){
	}
private:
	int x;
public:
	void operator()(){
		cout<<"xxxxxxxxxxxxxxxx"<<endl;
	}
}

int main(){
	function fun;
	fun();
}
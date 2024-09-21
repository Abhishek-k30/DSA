class FooBar {
    std:: mutex mx;
    std:: condition_variable cv;
    int turn;
private:
    int n;

public:
    FooBar(int n) {
        this->n = n;
        turn = 1;
    }

    void foo(function<void()> printFoo) {
        
        
        
        for (int i = 0; i < n; i++) {
            
            std:: unique_lock<std:: mutex> lock(mx);
        	while(turn!=1){
            cv.wait(lock);
        }
        	printFoo();
            
                    
        turn = 2;
        cv.notify_all();
        }

    }

    void bar(function<void()> printBar) {
        
       
        for (int i = 0; i < n; i++) {
            
            std:: unique_lock<std:: mutex> lock(mx);
             while(turn!=2){
            cv.wait(lock);
        }
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();
            turn = 1;
            cv.notify_all();
        }
        
        
    }
};
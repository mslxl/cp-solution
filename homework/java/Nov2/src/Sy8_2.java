public class Sy8_2 {
    public static void main(String[] args) {
        Choujiang a = new Choujiang();
        Thread t1 = new Thread(a,"抽奖箱1");
        Thread t2 = new Thread(a,"抽奖箱2");
        t1.start();
        t2.start();
    }
}
class Choujiang implements Runnable{
    int[] arr = {10,5,200,300,100,8,10,15,150};
    int num = arr.length;
    boolean[] flag = new boolean[arr.length];
    public void run(){
        if(num>0){
            int index = (int)(Math.random()*arr.length);
            int get = arr[index];
            if(flag[index]!=true){
                flag[index] = true;				System.out.println(Thread.currentThread().getName()+
                        " 又产生了一个"+get+"元大奖");
                num--;
            }
        }
    }
}

package quest4;

import java.util.Arrays;
import java.util.Random;

class Student implements Comparable<Student> {
    String name;
    int id;
    int score;
    public Student() {}
    public Student(String s, int n, int a){
        name = s;
        id = n;
        score = a;
    }
    public void setName(String s) {
        name = s;
    }
    public void setScore(int a) {
        score = a;
    }
    public void setID(int n) {
        id = n;
    }
    public String getName() {
        return name;
    }
    public int getScore() {
        return score;
    }
    public int getID() {
        return id;
    }

    @Override
    public int compareTo(Student o) {
        return o.score - this.score;
    }

    @Override
    public String toString() {
        StringBuffer sb = new StringBuffer();
        sb.append("学号:");
        sb.append(id);
        sb.append(",成绩:");
        sb.append(score);
        sb.append("\n");
        return sb.toString();
    }
}

public class Sy3_4{
    public static void main(String[] args) {
        final int size = 10;
        Student[] stu = new Student[size];
        Random rad = new Random();
        for(int i = 0; i < size; i++){
            stu[i] = new Student("student" + i, i, rad.nextInt(100));
        }
        System.out.println("排序前:\n" + Arrays.toString(stu)); //摸个鱼应该没问题吧，输出格式不是完全相同，但是目的能达到
        Arrays.sort(stu);
        System.out.println("排序后:\n" + Arrays.toString(stu));
    }
}
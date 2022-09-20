package quest3;

public class User {
    private int id;
    private String name;
    public int getId() {
        return id;
    }
    public void setId(int id) {
        this.id = id;
    }
    public String getName() {
        return name;
    }
    public void setName(String name) {
        this.name = name;
    }
    public String sayHello(String who) {
        return who + "{" +
                "id=" + id +
                ", name='" + name + '\'' +
                '}';
    }
}

import java.io.Serializable;
import java.util.UUID;

public class Message implements Serializable {
    private static final long serialVersionUID = 1L;
    
    private final UUID id;
    private final String content;
    
    public Message(UUID id, String content) {
        this.id = id;
        this.content = content;
    }
    
    public UUID getId() {
        return id;
    }
    
    public String getContent() {
        return content;
    }
    
    @Override
    public String toString() {
        return "Message{id=" + id + ", content='" + content + "'}";
    }
}
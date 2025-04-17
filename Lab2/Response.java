import java.io.Serializable;
import java.util.UUID;

public class Response implements Serializable {
    private static final long serialVersionUID = 1L;
    
    private final UUID messageId;
    private final String content;
    
    public Response(UUID messageId, String content) {
        this.messageId = messageId;
        this.content = content;
    }
    
    public UUID getMessageId() {
        return messageId;
    }
    
    public String getContent() {
        return content;
    }
    
    @Override
    public String toString() {
        return "Response{messageId=" + messageId + ", content='" + content + "'}";
    }
}
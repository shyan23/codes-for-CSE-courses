import java.io.*;
import java.net.*;
import java.util.*;

public class FaultClient {
    private static final String SERVER_ADDRESS = "localhost";
    private static final int SERVER_PORT = 8080;
    private static final int MAX_RETRIES = 3;
    private static final int RETRY_TIMEOUT = 2000; // ms
    
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        while (true) {
            System.out.print("Enter message (or 'exit' to quit): ");
            String input = scanner.nextLine();
            
            if ("exit".equalsIgnoreCase(input)) {
                break;
            }
            
            // Create a message with unique ID
            UUID messageId = UUID.randomUUID();
            Message message = new Message(messageId, input);
            
            // Send with retry logic
            Response response = sendWithRetry(message);
            
            if (response != null) {
                System.out.println("Server response: " + response.getContent());
            } else {
                System.out.println("Failed to send message after " + MAX_RETRIES + " attempts.");
            }
        }
        
        scanner.close();
        System.out.println("Client terminated.");
    }
    
    private static Response sendWithRetry(Message message) {
        int attempts = 0;
        
        while (attempts < MAX_RETRIES) {
            Socket socket = null;
            ObjectOutputStream out = null;
            ObjectInputStream in = null;
            
            try {
                attempts++;
                System.out.println("Attempt " + attempts + " to send message: " + message.getId());
                
                socket = new Socket(SERVER_ADDRESS, SERVER_PORT);
                socket.setSoTimeout(RETRY_TIMEOUT);
                
                // Important: Create output stream first to avoid deadlock
                out = new ObjectOutputStream(socket.getOutputStream());
                out.flush(); // Flush header information
                in = new ObjectInputStream(socket.getInputStream());
                
                // Send the message
                out.writeObject(message);
                out.flush();
                
                System.out.println("Message sent: " + message.getId());
                
                // Wait for and return the response
                Response response = (Response) in.readObject();
                System.out.println("Received response for message: " + response.getMessageId());
                return response;
                
            } catch (Exception e) {
                System.out.println("Attempt " + attempts + " failed: " + e.getMessage());
                
                if (attempts < MAX_RETRIES) {
                    System.out.println("Retrying in " + RETRY_TIMEOUT + "ms...");
                    try {
                        Thread.sleep(RETRY_TIMEOUT);
                    } catch (InterruptedException ie) {
                        Thread.currentThread().interrupt();
                    }
                }
            } finally {
                // Close resources
                try {
                    if (out != null) out.close();
                    if (in != null) in.close();
                    if (socket != null) socket.close();
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        }
        
        return null; // All retries failed
    }
}
import java.io.*;
import java.net.*;
import java.util.*;

public class FaultServer {
    private static final int PORT = 8080;
    // Store processed message IDs to detect duplicates
    private static final Set<UUID> processedMessages = Collections.synchronizedSet(new HashSet<>());
    // Store responses for messages to handle client retries
    private static final Map<UUID, String> responseCache = Collections.synchronizedMap(new HashMap<>());
    
    public static void main(String[] args) {
        try {
            ServerSocket serverSocket = new ServerSocket(PORT);
            System.out.println("Server started on port " + PORT);
            
            while (true) {
                Socket clientSocket = null;
                ObjectInputStream in = null;
                ObjectOutputStream out = null;
                
                try {
                    clientSocket = serverSocket.accept();
                    System.out.println("Client connected: " + clientSocket.getInetAddress());
                    
                    // Important: Create output stream first to avoid deadlock
                    out = new ObjectOutputStream(clientSocket.getOutputStream());
                    out.flush(); // Flush header information
                    in = new ObjectInputStream(clientSocket.getInputStream());
                    
                    // Read the message object
                    Message message = (Message) in.readObject();
                    System.out.println("Received: " + message);
                    UUID messageId = message.getId();
                    
                    String response;
                    
                    // Check if we've already processed this message
                    if (processedMessages.contains(messageId)) {
                        System.out.println("Duplicate message detected: " + messageId);
                        // Return cached response instead of reprocessing
                        response = responseCache.get(messageId);
                        System.out.println("Using cached response: " + response);
                    } else {
                        // Process the message
                        response = processMessage(message);
                        // Store the message ID and response
                        processedMessages.add(messageId);
                        responseCache.put(messageId, response);
                        System.out.println("Processed new message: " + messageId);
                    }
                    
                    // Send the response back to client
                    Response responseObj = new Response(messageId, response);
                    out.writeObject(responseObj);
                    out.flush();
                    System.out.println("Sent response: " + responseObj);
                    
                } catch (Exception e) {
                    System.out.println("Error handling client: " + e.getMessage());
                    e.printStackTrace();
                } finally {
                    // Close resources
                    try {
                        if (out != null) out.close();
                        if (in != null) in.close();
                        if (clientSocket != null) clientSocket.close();
                    } catch (IOException e) {
                        e.printStackTrace();
                    }
                }
            }
        } catch (IOException e) {
            System.out.println("Server error: " + e.getMessage());
            e.printStackTrace();
        }
    }
    
    private static String processMessage(Message message) {
        // Simulate processing time and potential failure
        try {
            System.out.println("Processing message: " + message.getContent());
            
            // Simulate processing time
            Thread.sleep(1000);
            
            // Simulate occasional processing failure
            if (Math.random() < 0.3) {
                System.out.println("Simulating processing failure!");
                throw new RuntimeException("Processing failed");
            }
            
            return "Processed: " + message.getContent() + " at " + new Date();
        } catch (InterruptedException e) {
            Thread.currentThread().interrupt();
            return "Error processing message: " + e.getMessage();
        }
    }
}
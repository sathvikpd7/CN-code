import java.io.*;
import java.net.*;
import java.util.*;

public class UDPClient {
    public static void main(String args[]) throws SocketException, IOException {
        Scanner sc = new Scanner(System.in);
        InetAddress ip = InetAddress.getByName("localhost");
        DatagramSocket clientSocket = new DatagramSocket();

        while (true) {
            byte[] sendBuffer;
            byte[] receiveBuffer = new byte[1024];

            System.out.println("\nClient:");
            String clientData = sc.nextLine();
            sendBuffer = clientData.getBytes();

            DatagramPacket sendPacket = new DatagramPacket(sendBuffer, sendBuffer.length, ip, 9902);
            clientSocket.send(sendPacket);

            if (clientData.equalsIgnoreCase("bye")) {
                System.out.println("Connection ended by client.");
                break;
            }

            DatagramPacket receivePacket = new DatagramPacket(receiveBuffer, receiveBuffer.length);
            clientSocket.receive(receivePacket);

            String serverData = new String(receivePacket.getData(), 0, receivePacket.getLength());
            System.out.println("\nServer: " + serverData);
        }
        clientSocket.close();
    }
}

import java.io.*;
import java.net.*;
import java.util.*;

public class UDPServer {
    public static void main(String args[]) throws SocketException, IOException {
        DatagramSocket serverSocket = new DatagramSocket(9902);
        Scanner sc = new Scanner(System.in);

        while (true) {
            byte[] receiveBuffer = new byte[1024];
            byte[] sendBuffer;

            DatagramPacket recvDPkt = new DatagramPacket(receiveBuffer, receiveBuffer.length);
            serverSocket.receive(recvDPkt);

            InetAddress ip = recvDPkt.getAddress();
            int portNo = recvDPkt.getPort();

            String clientData = new String(recvDPkt.getData(), 0, recvDPkt.getLength());
            System.out.println("\nClient: " + clientData);

            System.out.println("\nServer:");
            String serverData = sc.nextLine();
            sendBuffer = serverData.getBytes();

            DatagramPacket sendPacket = new DatagramPacket(sendBuffer, sendBuffer.length, ip, portNo);
            serverSocket.send(sendPacket);

            if (serverData.equalsIgnoreCase("bye")) {
                System.out.println("Connection closed by server.");
                break;
            }
        }
        serverSocket.close();
    }
}

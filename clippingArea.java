/**
 * Algortimo clippingArea Cohen-Sutherland
 * 
 * @author Juan Pablo Castaño Duque
 */
import java.awt.Canvas;
import java.awt.Color;
import java.awt.Graphics;
import javax.swing.JFrame;
import java.util.Scanner; 
public class clippingArea extends Canvas {
    static int x;
    static String ca1,ca2,ca3,ca4,ca5,ca6,ca7,ca8,ca9,caI, caF;
    static boolean zero;
        public static void main(String args[])
    {   while (true){
        definirClippingAreas();
        pedirTecla();
        clippingArea();
        zero = zeros();
        
        JFrame frame = new JFrame("My Drawing");
        Canvas canvas = new clippingArea();
        canvas.setSize(450, 450);
        frame.add(canvas);
        frame.pack();
        frame.setVisible(true);
        
    }
        
    }
    public void paint(Graphics g) {

            g.setColor(Color.red);
            g.drawRect(150,150, 150, 150);
            if (zero == true) {
            g.setColor(Color.green);
            g.drawLine(x,0,x, 150);
            g.setColor(Color.blue);
            g.drawLine(x,150,x,300);
            g.setColor(Color.green);
            g.drawLine(x,300,x, 450);
        }
        else{
            g.setColor(Color.green);
            g.drawLine(x,0,x,450);
        }
 
    }
    public static void pedirTecla(){
        System.out.println ("Introduzca la coordenada x del punto inicial:");
        Scanner entrada = new Scanner (System.in); 
        x = entrada.nextInt ();
    }
    public static void definirClippingAreas(){
        ca1 = "1001";
        ca2 = "1000";
        ca3 = "1010";
        ca4 = "0001";
        ca5 = "0000";
        ca6 = "0010";
        ca7 = "0101";
        ca8 = "0100";
        ca9 = "0110";
    }
    public static void clippingArea(){
        if (x < 150) {
            caI = ca1;
            caF = ca7;
        } 
        else if (x> 300) {
            caI = ca3;
            caF = ca9;
        }
        else{
            caI = ca2;
            caF = ca8;
        }
    }
    public static boolean zeros(){
        int i = 0;



        while (i<= 3){
            if ((caI.charAt(i) == caF.charAt(i)) && (caI.charAt(i) == '1' )){
                return false;
            }
            i ++;
        }
        return true;
        
    }
}
    

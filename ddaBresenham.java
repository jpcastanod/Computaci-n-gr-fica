/**
 * Algortimo dda para graficas linea
 * 
 * @author Juan Pablo Castaño Duque

 */
import java.awt.Canvas;
import java.awt.Color;
import java.awt.Graphics;
import javax.swing.JFrame;
import java.util.Scanner; 
public class dda extends Canvas
{  
   static int  x1, x2, y1, y2, incE, incNE, d, deltaXB, deltaYB;
   static float pasos, xIncrementodda, yIncrementodda;
    public static void main(String args[])
    {   
        while (true){
        int deltaX, deltaY;
        puntoInicial();
        puntoFinal();
        deltaX = Math.abs (x2-x1);
        deltaY = Math.abs (y2-y1);
        pasos = comparaciondda(deltaX,deltaY);
        xIncrementodda = deltaX/pasos;
        yIncrementodda = deltaY/pasos;
        deltaXB = x2-x1;
        deltaYB = y2-y1;
        incE = 2*deltaYB;
        incNE = (2*deltaYB) - (2 *deltaXB);
        d = (2*deltaYB) - (deltaXB);
        JFrame frame = new JFrame("My Drawing");
        Canvas canvas = new dda();
        canvas.setSize(400, 400);
        frame.add(canvas);
        frame.pack();
        frame.setVisible(true);
    }
               
    }
    public void paint(Graphics g) {
        int i, x1dda, y1dda, yb, xb;
        float cX1, cY1;
        yb = y1;
        xb = x1;
        i = 0;
        x1dda = x1;
        y1dda = y1;
        cX1 = x1;
        cY1 = y1;
       //dibujo dda
        while(i<pasos){
        g.setColor(Color.blue);
        g.drawLine(x1dda, y1dda, x1dda, y1dda);
        cX1 = cX1 + xIncrementodda;
        cY1 = cY1 + yIncrementodda;
        x1dda = Math.round(cX1);
        y1dda = Math.round(cY1);
        i++;
    }
    //dibujo Bresenham
        i = 0;
        while (xb<=x2) {
            g.setColor(Color.red);
            g.drawLine(xb, yb, xb, yb);

            if (d <= 0){
                d += incE;
            }
            else {
                d += incNE;
                yb++;
            }
            xb++;
        }
        
       
    }
    public static void puntoInicial(){
        System.out.println ("Introduzca la coordenada x del punto inicial:");
        Scanner entrada = new Scanner (System.in); 
        x1 = entrada.nextInt ();
        System.out.println ("Introduzca la coordenada y del punto inicial:");
        y1 = entrada.nextInt();
    }
    public static void puntoFinal(){
        System.out.println ("Introduzca la coordenada x del punto final:");
        Scanner entrada = new Scanner (System.in); 
        x2 = entrada.nextInt ();
        System.out.println ("Introduzca la coordenada y del punto final:");
        y2 = entrada.nextInt();
    }
    public static float comparaciondda(float deltaX, float deltaY){
        if (deltaX > deltaY){
            return deltaX;
        }
        return deltaY;
    }
}

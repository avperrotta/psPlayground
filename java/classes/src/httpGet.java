/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author perrotta
 */
import com.cycling74.max.*;
import static com.cycling74.max.DataTypes.FLOAT;
import java.io.*;
import java.net.*;

public class httpGet extends MaxObject {
    
  String output;
  String urlStr;
  public void bang() {
    
  }
  
  public void list(Atom[] args)
   {
      post("Received list message at inlet "+getInlet());
      //loop through all the atoms in the list
      Atom a;
      for(int i = 0; i < args.length; i++)
      {
        a = args[i];
        if(a.isFloat()){
            post("List element "+i+" is a floating point atom with a value of "+a.getFloat());
        }
        else if(a.isInt()){
            post("List element "+i+" is an integer atom with a value of "+a.getInt());
        }  
        else if(a.isString()){
            post("List element "+i+" is a String atom with a value of "+a.getString());
        }
           
      }
   }
  
  public void anything(String msg, Atom[] args)
   {
      
      if(msg.equals("getUrl")){
          if(args.length == 1){
              float f;
              f = Float.parseFloat(getHTML(args[0].toString()));
              outlet(0, f);
          }
      }
   }

  
  
  
  public String getHTML(String urlToRead) {
      urlStr = urlToRead;
      Thread t = new Thread(){
           public void run()
           {
                URL url;
                HttpURLConnection conn;
                BufferedReader rd;
                String line;
                String result = "";
                try {
                   url = new URL(urlStr);
                   conn = (HttpURLConnection) url.openConnection();
                   conn.setRequestMethod("GET");
                   rd = new BufferedReader(new InputStreamReader(conn.getInputStream()));
                   while ((line = rd.readLine()) != null) {
                      result += line;
                   }
                   rd.close();
                } catch (IOException e) {
                   e.printStackTrace();
                } catch (Exception e) {
                   e.printStackTrace();
                }
                output = result;
           }
      };
      t.start();
      return output;
      
   }
  
  
}

import java.io.*;
import java.util.Scanner;

public class UI
{
  static private Drive drive = new Drive();
	public static String[] parseCommand(String command)
	{
    //return array of String elements, like argv
    int i=0;
    
    String [] tokens = new String [3];
    Scanner scan = new Scanner(command);
    while(scan.hasNext()&&i<4)
    {
       tokens[i] = scan.next();
       i++;
    }
		
		return tokens;
  }

	public static void importFile(String[] tokens)
	{
    String data = "";
    try 
      {
          //tokens must have 3 arguments
        if(tokens.length!=3)
        {
          throw new IllegalArgumentException("Wrong usage");  
        }
          //Making sure name is 1 lowercase char
        if(tokens[2].length()>1||tokens[2].charAt(0)<'a'||tokens[2].charAt(0)>'z')
        {
          throw new IllegalArgumentException("Invalid filename");  
        }
          //Opening file and 
          
        FileReader file = new FileReader(tokens[1]);
          
        BufferedReader reader = new BufferedReader(file);
        String line;
        while ((line = reader.readLine()) != null)
        {
          data += line + "\n";
        }
          reader.close();
        }
          
    catch (FileNotFoundException e)
    {
      System.err.println(e.getMessage());
    } 
    catch (IOException e) 
    {
      System.err.println(e.getMessage());
    }
          
    catch(IllegalArgumentException e)
    {
      System.out.println(e.getMessage());
      return;
    }
    
    //Creating entry in fObjects
    drive.setFile(tokens[2].charAt(0), data);
	}
	
	public static void exportFile(String[] tokens)
	{
		try 
    {
//tokens must have 3 arguments
      if(tokens.length!=3) 
      {
        throw new IllegalArgumentException("Wrong usage");  
      }

 //Throwing error if file doesnt exist in VS    
      if(drive.getFile(tokens[1].charAt(0))==null)
      { 
        throw new IllegalArgumentException("File does not exist in VFS");
      }
      File file = new File(tokens[2]);

     //Throwing error if file exists
      if(file.exists())
      {
        throw new IllegalArgumentException("Error, file exists.");
      }
      BufferedWriter writer = new BufferedWriter(new FileWriter(tokens[2]));

    // Writing the string to the file
      writer.write(drive.getFile(tokens[1].charAt(0)));
      writer.close();
    }
    catch (IOException e) 
    {
     System.err.println(e.getMessage());
    }    
    catch(IllegalArgumentException e)
    {
      System.out.println(e.getMessage());
      return;
    }

	}

	public static void ls(String[] tokens)
	{
		for(char m:drive.names())
    {
      System.out.println(m+" "+drive.getFile(m).length());
    }
	}

}
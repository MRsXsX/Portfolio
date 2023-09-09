import java.util.HashMap;

public class Drive
{
  //Hashmap with key as Character and String as value
  HashMap<Character, String> fileObjects;

  public Drive()
  {  
    fileObjects = new HashMap<>();
  }
  
	public void setFile(char name, String data)
	{
    fileObjects.put(name, data);
  }

	public String getFile(char name)
	{
		return fileObjects.get(name);
	}

	public char[] names()
	{
    int i=0;
    char names[]= new char[fileObjects.size()];
    for(char m: fileObjects.keySet())
    {
      names[i++]=m;
    }
		return names;
	}
}
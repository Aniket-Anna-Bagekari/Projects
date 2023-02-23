import java.util.*;

class Student
{
    public String SName;
    public int iMarks;
    public int RollNo;

    public static int Generator;

    static
    {
        Generator = 0;
    }

    public Student(String str, int iNo)
    {
        this.SName = str;
        this.iMarks = iNo;
        Generator++;
        this.RollNo = Generator;
    }

    public void Display()
    {
        System.out.println("Roll No_"+RollNo+"    Name : "+SName+"    Marks : "+iMarks);
    }
}

class DBMS
{
    public LinkedList <Student> lobj;

    public DBMS()
    {
        lobj = new LinkedList();
    }

    public void StartDBMS()
    {
        System.out.println("Marvellous Customised DBMS started successfully....");

        Scanner sobj = new Scanner(System.in);
        String Query = " ";
        int QuerySize = 0;

        while(true)
        {
            System.out.print("Marvellous DBMS : > ");
            Query = sobj.nextLine();

            String Tokens[] = Query.split(" ");
            QuerySize = Tokens.length;

            if(QuerySize == 1)
            {
                if("help".equals(Tokens[0]))
                {
                    System.out.println();
                    System.out.println("*  This application is used to demonstrate the features of Customized DBMS  *");
                    System.out.println("1. Insert new record           : insert into student values Name Marks");
                    System.out.println("2. Display all the table data  : select * from student");
                    System.out.println("3. Display specific table data : select * from student where Name = Aniket");
                    System.out.println("                               : select * from student where Marks = 95");
                    System.out.println("4. Delete specific table data  : delete from student where RollNo = 3");
                    System.out.println("                               : delete from student where Name = Ram");
                    System.out.println("5. Addition of Marks           : select sum(marks) from student");
                    System.out.println("6. Minimum of Marks            : select min(marks) from student");
                    System.out.println("7. Maximum of Marks            : select max(marks) from student");
                    System.out.println("6. Average of Marks            : select avg(marks) from student");
                    System.out.println("8. Terminate the project       : exit");
                    System.out.println();
                    System.out.println("NOTE : All queries are Case Sensitive so write all queries in small case.");
                    System.out.println();
                }
                else if("exit".equals(Tokens[0]))
                {
                    System.out.println("Thank you for using our customized DBMS.");
                    break;
                }
                else
                {
                    System.out.println("ERROR : Command not found !!!");
                }
            }
            else if(QuerySize == 4)
            {
                if("select".equals(Tokens[0]))
                {
                    if("*".equals(Tokens[1]))
                    {
                        DisplayAll();
                    }
                    else if("sum(marks)".equals(Tokens[1]))
                    {
                        if("student".equals(Tokens[3]))
                        {
                            Sum();
                        }
                    }
                    else if("min(marks)".equals(Tokens[1]))
                    {
                        if("student".equals(Tokens[3]))
                        {
                            Min();
                        }
                    }
                    else if("max(marks)".equals(Tokens[1]))
                    {
                        if("student".equals(Tokens[3]))
                        {
                            Max();
                        }
                    }
                    else if("avg(marks)".equals(Tokens[1]))
                    {
                        if("student".equals(Tokens[3]))
                        {
                            Avg();
                        }
                    }
                    else
                    {
                        System.out.println("ERROR : Command not found !!!");
                    }
                }
            }
            else if(QuerySize == 6)
            {
                if("insert".equals(Tokens[0]))
                {
                    if("student".equals(Tokens[2]))
                    {
                        Insert(Tokens[4],Integer.parseInt(Tokens[5]));
                    }
                }
            }
            else if(QuerySize == 7)
            {
                if("delete".equals(Tokens[0]))
                {
                    if(("student".equals(Tokens[2])) && ("where".equals(Tokens[3])))
                    {
                        Delete(Tokens[6]);
                    }
                }
            }
            else if(QuerySize == 8)
            {
                if("select".equals(Tokens[0]))
                {
                    if("*".equals(Tokens[1]) && ("student".equals(Tokens[3])))
                    {
                        if("where".equals(Tokens[4]))
                        {
                            DisplaySpecific(Tokens[7]);
                        }
                    }
                }
            }
        }  // End of while
    }  // End of StartDBMS


    // All SQL queries should be implemented here
    // insert into Student values(____,____);
    public void Insert(String str, int iNo)
    {
        Student sobj = new Student(str,iNo);
        lobj.add(sobj);
    }

    // select * from Student;
    public void DisplayAll()
    {
        for(Student sRef : lobj)  // for each loop
        {
            sRef.Display();
        }
    }

    // select * from Student where RollNo = 3;
    public void DisplaySpecific(int iValue)
    {
        for(Student sRef : lobj)
        {
            if(sRef.RollNo == iValue)
            {
                sRef.Display();
                break;
            }
        }
    }

    // select * from Student where Name = 'Rutuja';
    public void DisplaySpecific(String str)
    {
        for(Student sRef : lobj)
        {
            if(str.equals(sRef.SName))
            {
                sRef.Display();
                break;
            }
        }
    }

    // delete from Student where RollNo = 3;
    public void Delete(int iNo)
    {
        int index = 0;

        for(Student sRef : lobj)
        {
            if(sRef.RollNo == iNo)
            {
                lobj.remove(index);
                break;
            }
            index++;
        }
    }

    // delete from Student where Name = 'Ram';
    public void Delete(String str)
    {
        int index = 0;

        for(Student sRef : lobj)
        {
            if(str.equals(sRef.SName))
            {
                lobj.remove(index);
                break;
            }
            index++;
        }
    }

    // Addition of Marks
    public void Sum()
    {
        int iSum = 0;

        for(Student sRef : lobj)
        {
            iSum = iSum + (sRef.iMarks);
        }

        System.out.println("Summation of Marks : "+iSum);
    }

    // Maximum of Marks
    public void Max()
    {
        int iMax = 0;

        for(Student sRef : lobj)
        {
            if(sRef.iMarks > iMax)
            {
                iMax = sRef.iMarks;
            }
        }

        System.out.println("Maximum is : "+iMax);
    }

    // Minimum of Marks
    public void Min()
    {
        Student s = lobj.get(0);

        int iMin = s.iMarks;

        for(Student sRef : lobj)
        {
            if(sRef.iMarks < iMin)
            {
                iMin = sRef.iMarks;
            }
        }

        System.out.println("Minimum is : "+iMin);
    }

    // Average of Marks
    public void Avg()
    {
        int iSum = 0;

        for(Student sRef : lobj)
        {
            iSum = iSum + (sRef.iMarks);
        }

        System.out.println("Average is : "+(iSum / lobj.size()));
    }
}

class SourceCode
{
    public static void main(String Arg[])
    {
        DBMS dobj = new DBMS();

        dobj.StartDBMS();
    }
}
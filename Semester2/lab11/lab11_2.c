#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define EMAIL_MAX 50 // Rozmiar tablicy email w strukturze.
#define F_NAME_MAX 50 // Rozmiar tablicy first_name w strukturze.
#define L_NAME_MAX 50 // Rozmiar tablicy last_name w strukturze.

typedef struct
{
char first_name[F_NAME_MAX]; // Uwaga: tablica!
char last_name[L_NAME_MAX]; // Uwaga: tablica!
unsigned short age;
char email[EMAIL_MAX];
} Student_v2;

Student_v2 students[] = {
	{"Felic", "Wheal", 26, "fwheal0@wisc.edu" }, 
	{"Laurent", "Usmar", 23, "lusmar1@creativecommons.org" }, 
	{"Cathi", "Josephi", 26, "cjosephi2@patch.com" }, 
	{"Tuesday", "Bailes", 24, "tbailes3@live.com" }, 
	{"Florry", "Cassius", 27, "fcassius4@smugmug.com" }, 
	{"Toby", "Anstie", 33, "tanstie5@qq.com" }, 
	{"Nick", "Johnsey", 26, "njohnsey6@answers.com" }, 
	{"Gearalt", "Fishwick", 33, "gfishwick7@studiopress.com" }, 
	{"Merilee", "Burchess", 24, "mburchess8@newyorker.com" }, 
	{"Jillie", "Gonnin", 34, "jgonnin9@eepurl.com" }, 
	{"Nessi", "Philipet", 32, "nphilipeta@wunderground.com" }, 
	{"Irena", "Bartolijn", 32, "ibartolijnb@google.ru" }, 
	{"Danette", "Boulton", 32, "dboultonc@clickbank.net" }, 
	{"Tudor", "Kollasch", 28, "tkollaschd@jigsy.com" }, 
	{"Weider", "Bilfoot", 24, "wbilfoote@tumblr.com" }, 
	{"Eyde", "Haggith", 33, "ehaggithf@globo.com" }, 
	{"Margaretha", "Tann", 28, "mtanng@smugmug.com" }, 
	{"Cassandra", "Ceaplen", 26, "cceaplenh@nps.gov" }, 
	{"Marillin", "Kivlehan", 25, "mkivlehani@chronoengine.com" }, 
	{"Augustine", "Hyder", 23, "ahyderj@rambler.ru" }, 
	{"Clarie", "Heisham", 23, "cheishamk@reuters.com" }, 
	{"Daisie", "Lygoe", 33, "dlygoel@devhub.com" }, 
	{"Quillan", "Steptow", 35, "qsteptowm@cafepress.com" }, 
	{"Bettine", "Whellams", 30, "bwhellamsn@canalblog.com" }, 
	{"Darill", "Doree", 27, "ddoreeo@craigslist.org" }, 
	{"Del", "Callington", 32, "dcallingtonp@google.co.jp" }, 
	{"Francis", "McDool", 35, "fmcdoolq@themeforest.net" }, 
	{"Wynona", "Bilfoot", 23, "wbilfoote2@tumblr.com" }, 
	{"Blythe", "McTeer", 22, "bmcteerr@tumblr.com" }, 
	{"Christian", "Trass", 29, "ctrasss@apple.com" }, 
	{"Wang", "Gayter", 29, "wgaytert@meetup.com" }, 
	{"Jill", "Wiper", 18, "jwiperu@mayoclinic.com" }, 
	{"Weider", "Bilfoot", 23, "bilfooter@tumblr.com" }, 
	{"Min", "Wicher", 32, "mwicherv@dyndns.org" }, 
	{"Jennine", "Cure", 33, "jcurew@4shared.com" }, 
	{"Ivan", "Orrom", 31, "iorromx@bigcartel.com" }, 
	{"Sharona", "Crosfield", 29, "scrosfieldy@google.co.jp" }
};

void print_student(const Student_v2 *student)
{
    assert(student != NULL);
    printf("Dane studenta: %s %s, wiek: %u, adres: %s\n", student->first_name, student->last_name, student->age, student->email);
}

int main()
{
    FILE *pFile=fopen("newStudents.bin","wb+");
    if (! pFile ) {
        printf ("Nie mozna utworzyc pliku.\n") ;
        exit ( EXIT_FAILURE ) ;
    }

    fpos_t position;
    fgetpos(pFile,&position);


    int nStudents=sizeof(students)/sizeof(*students);


    fwrite(students,sizeof(Student_v2),nStudents,pFile);

	
    fsetpos(pFile,&position);

    Student_v2 studentsTab[nStudents];

	fread(studentsTab,sizeof(Student_v2),nStudents,pFile);

    for (size_t i = 0; i < nStudents; i++)
    {
		print_student(studentsTab+i);
    }

    fclose(pFile);
    return 0;
}

#include "main.h"

//NOT okunan ve yazılacak dosya adını string ile dışarıdan al
// printf lerin lazım olmayanları sil 
// yazılan dosyayı close ile kapat          ++
//malloc ile acılan yeerleri free le        ++
//bir daha incele !!!!!!!!!!!

float parse(char *line,int eleman)
{
    char **split=ft_split(line);
    char **parsesplit = (char **)malloc(sizeof(char)); //sadece 1 adet return olacağı için 1 adetlik yer açtım
    parsesplit[0] = malloc(sizeof(char) * (ft_strlen(split[eleman]) + 1));
    parsesplit[0] = ft_strdup(split[eleman]);
    float sonuc=atof(parsesplit[0]);
    free (parsesplit[0]);
    free (parsesplit);
    free (split);
    return (sonuc);
}

int main(int ac,char **av)
{
    if(ac==4)
    {
        float scanR;
        scanR = atof(av[1]);
        char *line;
        int fd=open(av[2],O_RDONLY);
        int satir=1;

        while (get_next_line(fd,&line)>0) //okunan dosyanın satır sayısı bulma
        {
            //printf("%s\n",satir,line);
            satir++;
        }

        close(fd);
        float **map;//satır sayısı bilinen dosya için 2boyutlu float dizisi için yer açma
        map = (float **) malloc(satir * sizeof(float *));
        for(int i=0;i<satir;i++)
            map[i] = (float *) malloc(3 * sizeof(float));

        char **veriler;
        fd = open(av[2],O_RDONLY);

        satir = 0;
        while (get_next_line(fd,&line)>0)//map içine sırayla x y z değerlerinin atanması
        {
            for(int eleman=0;eleman<3;eleman++)
            {
                map[satir][eleman]=parse(line,eleman);
            }
            satir++;
            //printf("%d",satir+1);
            //printf("%s\n",line);
        }
        //printf("\n%d\n",satir);
        float x_top = 0;
        float y_top = 0;
        float z_top = 0;
        int data_count = 0;

        FILE *new_fd;
        new_fd = fopen(av[3], "w");

        for(int check = 0; check < satir; check++)
        {
            data_count = 0;
            x_top = 0;
            y_top = 0;
            z_top = 0;
            for(int i = 0; i < satir; i++)
            {
                if(fabsf((map[check][0])-(map[i][0])) <= scanR)//x değerleri istenilen uzaklıkta ise
                {
                    if(fabsf((map[check][1])-(map[i][1])) <= scanR)//y değerleri istenilen uzaklıkta mı
                    {
                        if(fabsf((map[check][2])-(map[i][2])) <= scanR)//z değerleri istenilen uzaklıkta mı
                        {
                            if(check != i)
                            {
                                x_top += map[i][0];
                                y_top += map[i][1];
                                z_top += map[i][2];
                                data_count++;
                            }
                        }
                    }
                }
            }
            if(data_count!=0)
                fprintf(new_fd, "%f %f %f\n",(x_top/data_count),(y_top/data_count),(z_top/data_count));
            else
                fprintf(new_fd, "%f %f %f\n",(map[check][0]),(map[check][1]),(map[check][2]));
        }
        close(fd);
        close(fileno(new_fd));
        for(int i=0;i<satir;i++)
            free(map[i]);
        free(map);

        return 0;
    }
    printf("eksik argüman");
    return 0;
}
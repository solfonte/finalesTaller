/***
7) Escriba un programa que reciba por línea de comandos un Puerto y una IP.
El programa debe conectarse al destino indicado y quedar en escucha de paquetes con la forma
“d..d|d..d|… >”. El programa debe imprimir en stdout el checksum (sumatoria módulo 256) de cada paquete.
Cuando se reciba un paquete vacío se debe finalizar ordenadamente.
***/


//Servidor
while (!termine){

  recv(fd,&buf,sizeof(buf),0);
  if (buf == '>' && i = 2){
    termine = true;
  }else if (buf == '>'){
    int num = std::stoi (numText);
    acumulador += num;
    numText.clear();
    acumulador = acumulador % 256;
    std::cout << " checksum " << acumulador <<'\n';
    i = 1;
  }else if (buf == '|'){
    int num = std::stoi (numText);
    acumulador += num;
    numText.clear();
  }else{
    i = 0;
    numText.push_back(buf);
  }
}

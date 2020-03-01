#Montar modulos kernel
insmod /sopes2/cpu/m_cpu_201443728.ko
insmod /sopes2/ram/m_ram_201443728.ko
insmod /sopes2/processes/m_processes_201443728.ko

pm2 start /sopes/so_puno-api/app.js 

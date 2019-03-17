##　27-31　G2.9 std_alloc

<img src="017.jpg" style="zoom: 100%" div align=center> 
<img src="018.jpg" style="zoom: 100%" div align=center> 
<img src="019.jpg" style="zoom: 100%" div align=center> 
<img src="020.jpg" style="zoom: 100%" div align=center> 
<img src="021.jpg" style="zoom: 100%" div align=center> 
- 注意在deallocate中并没有释放已经分配的内存。
<img src="022.jpg" style="zoom: 100%" div align=center> 
<img src="023.jpg" style="zoom: 100%" div align=center> 
- 注意在第7页，如果start_free==0时，如果将之前已分配但没有使用的内存，再次分割，对于多进程的机器会有较大的后果。从其他进程还可能追加内存理解。
<img src="024.jpg" style="zoom: 100%" div align=center> 
<img src="025.jpg" style="zoom: 100%" div align=center> 
<img src="026.jpg" style="zoom: 100%" div align=center> 
<img src="027.jpg" style="zoom: 100%" div align=center> 

 res= reinit_io_cache(&info, READ_CACHE, 0L, FALSE, FALSE);
 ok(res == 0, "cache turned to read");

 for (ulong i= 0, curr_size= 0; i < n_frag; i++, copied_size
+= curr_size)
 {
curr_size= rand() % (2 * (total_size - copied_size) /
(n_frag - i));

 DBUG_ASSERT(curr_size <= total_size - copied_size || i ==
n_frag - 1);

 res= my_b_copy_to_file(&info, file, curr_size);
 ok(res == 0, "%lu of the cache copied to file",
curr_size);

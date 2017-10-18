int main(int argc, char **argv) {
	int ret;
	unsigned lcore_id;
	ret = rte_eal_init(argc, argv);
	if (ret < 0)
		rte_panic("Cannot init EAL\n");
	
	/* call lcore_hello() on every slave lcore */
	RTE_LCORE_FOREACH_SLAVE(lcore_id) {
		rte_eal_remote_launch(lcore_hello, NULL, lcore_id);
	}
	
	/* call it on master lcore too */
	lcore_hello(NULL);
	
	ret_eal_mp_wait_lcore();
	
	return 0;
}

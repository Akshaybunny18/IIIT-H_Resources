files = findmax swap Fbub loop bubsort fibo selsort
test_files = $(files:=-test.py)

all:

	@for file in $(test_files); do \
		python3 $$file; \
	done

OUT=../../out/priority_queue
CUNIT_INCLUDE=/opt/homebrew/include/
CUNIT_LIB=/opt/homebrew/Cellar/cunit/2.1-3/lib

$(shell if [ ! -e $(OUT) ];then mkdir -p $(OUT); fi)

test:
	gcc -Wno-nullability-completeness \
		-I ${CUNIT_INCLUDE} \
		-L ${CUNIT_LIB} \
		-l cunit \
		priority_queue.c priority_queue_test.c \
		-o ${OUT}/priority_queue_test
run:
	${OUT}/priority_queue_test

clean:
	rm -rf ${OUT}
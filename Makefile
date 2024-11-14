TARGET?=binaryTree #linearList 
all: $(patsubst %,all_%,$(TARGET))

all_%:
	@$(MAKE) -C $*

run: $(patsubst %,run_%,$(TARGET))

run_%:
	@$(MAKE) -C $* run

# 定义一个伪目标来遍历真实目标并执行它们
test: $(patsubst %,test_%,$(TARGET))

# 使用模式规则为每个目标创建一个测试规则
test_%:
	@$(MAKE) -C $* test

clean: $(patsubst %,clean_%,$(TARGET))

clean_%:
	@$(MAKE) -C $* clean

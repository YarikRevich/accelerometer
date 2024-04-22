.ONESHELL:

.PHONY: help
.DEFAULT_GOAL := help
help:
	@grep -h -E '^[a-zA-Z_-]+:.*?## .*$$' $(MAKEFILE_LIST) | awk 'BEGIN {FS = ":.*?## "}; {printf "\033[36m%-30s\033[0m %s\n", $$1, $$2}'

.PHONY: clean
clean: ## Cleans generated core files
ifneq (,$(wildcard ./Debug))
	@rm -r ./Debug

	@echo "Debug directory has been successfully deleted"
else
	@echo "Debug directory does not exist"
endif

ifneq (,$(wildcard ./Core/Src/main.c))
	@find ./Core/Src -name "*.cpp" | xargs -I {} rm {}
	@cd ./Core/Src && \
		for file in *; do \
			mv "$$file" "`echo $$file | sed 's/\.c$$/.cpp/'`"; \
		done

	@echo "*.c files rename operation was performed successfully"
else
	@echo "*.c files intented to be renamed don't exist"
endif

.PHONY: generate
generate: ## Generate ProtocolBuffers files(used mainly for development)
	@protoc -I./Resources/Proto/Container --pyi_out=./Scripts/cli/src/proto Content/data.proto request.proto response.proto
	@protoc -I./Resources/Proto/Container --python_out=./Scripts/cli/src/proto Content/data.proto request.proto response.proto
	@protoc --plugin=/Volumes/Files/embedded/university/project/deps/EmbeddedProto/venv/bin/protoc-gen-eams -I./Resources/Proto/Container --eams_out=./External/Proto/Generated Content/data.proto request.proto response.proto
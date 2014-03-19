# Makefile for executing all Ruby unit tests

.PHONY: all
all:	.bundle
	bundle exec rake

# Fetch all dependencies using the Gemfile
.bundle: Gemfile Gemfile.lock
	bundle --path $@
	touch $@

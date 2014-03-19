# This is an example of how to unit-test Ruby code using rspec.
# Please read this simple page:
#  http://blog.teamtreehouse.com/an-introduction-to-rspec

require 'spec_helper'
require 'a_ruby_example'

describe ARubyExample do

  describe "banner functionality" do

    it "sets the default banner" do
      example = ARubyExample.new
      example.banner.should == "default"
    end

    it "should not be possible to set the banner after creation" do
      example = ARubyExample.new
      expect { example.banner = "set again" }.to raise_error
    end

    it "must be possible to specify a banner" do
      my_banner = "an example banner"
      example = ARubyExample.new(my_banner)
      example.banner.should == my_banner
    end

  end

  describe "padding" do

    before do
      @example = ARubyExample.new("a banner for test purposes")
    end

    it "should have no padding per default" do
      @example.padded_banner.should == @example.banner
    end

    it "should use a supplied padding upon request" do
      @example.padded_banner("+").should == "+#{@example.banner}+"
    end

    it "should use a preset padding if it exists" do
      @example.padding = "preset"
      example.padded_banner.should == "preset#{@example.banner}preset"
    end

  end

  describe "additive capabilities" do

    it "can concatenate strings" do
      ARubyExample.add("foo", "bar").should == "foobar"
    end

    it "can add integers" do
      ARubyExample.add(1, 2).should == 3
    end

  end

end

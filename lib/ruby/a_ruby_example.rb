# This class serves as an example of Ruby syntax. It is also used when
# demonstrating a test case.
#
# Please have a look at: https://github.com/bbatsov/ruby-style-guide

class ARubyExample
  attr_reader :banner
  attr_writer :padding

  def initialize(banner = "default")
    @banner = banner
    @padding = ""
  end

  def padded_banner(padding = @padding)
    "#{padding}#{@banner}#{padding}"
  end

  def self.add(a, b)
    a + b
  end

end

#
# module.re: Methods of the Module builtin
# Copyright (C)2010 Tony Arcieri
# 
# Redistribution is permitted under the MIT license.  See LICENSE for details.
#

module Module
  def class; Module; end
  
  def call(receiver, :to_s, args, block)
    (:reia_module, name) = receiver
    name.to_string()
  end
  
  def call(receiver, :inspect, args, block)
    receiver.to_s()
  end

  def call(receiver, method, args, block)
    (:reia_module, name) = receiver
    erl.apply(name, method, [args, block])
  end
end

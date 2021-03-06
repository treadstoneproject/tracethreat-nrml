//
// Autogenerated by Thrift Compiler (1.0.0-dev)
//
// DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
//


//HELPER FUNCTIONS AND STRUCTURES

Authentication_pingActive_args = function(args) {
  this.genNum = null;
  if (args) {
    if (args.genNum !== undefined) {
      this.genNum = args.genNum;
    }
  }
};
Authentication_pingActive_args.prototype = {};
Authentication_pingActive_args.prototype.read = function(input) {
  input.readStructBegin();
  while (true)
  {
    var ret = input.readFieldBegin();
    var fname = ret.fname;
    var ftype = ret.ftype;
    var fid = ret.fid;
    if (ftype == Thrift.Type.STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
      if (ftype == Thrift.Type.I32) {
        this.genNum = input.readI32().value;
      } else {
        input.skip(ftype);
      }
      break;
      case 0:
        input.skip(ftype);
        break;
      default:
        input.skip(ftype);
    }
    input.readFieldEnd();
  }
  input.readStructEnd();
  return;
};

Authentication_pingActive_args.prototype.write = function(output) {
  output.writeStructBegin('Authentication_pingActive_args');
  if (this.genNum !== null && this.genNum !== undefined) {
    output.writeFieldBegin('genNum', Thrift.Type.I32, 1);
    output.writeI32(this.genNum);
    output.writeFieldEnd();
  }
  output.writeFieldStop();
  output.writeStructEnd();
  return;
};

Authentication_pingActive_result = function(args) {
  this.success = null;
  if (args) {
    if (args.success !== undefined) {
      this.success = args.success;
    }
  }
};
Authentication_pingActive_result.prototype = {};
Authentication_pingActive_result.prototype.read = function(input) {
  input.readStructBegin();
  while (true)
  {
    var ret = input.readFieldBegin();
    var fname = ret.fname;
    var ftype = ret.ftype;
    var fid = ret.fid;
    if (ftype == Thrift.Type.STOP) {
      break;
    }
    switch (fid)
    {
      case 0:
      if (ftype == Thrift.Type.BOOL) {
        this.success = input.readBool().value;
      } else {
        input.skip(ftype);
      }
      break;
      case 0:
        input.skip(ftype);
        break;
      default:
        input.skip(ftype);
    }
    input.readFieldEnd();
  }
  input.readStructEnd();
  return;
};

Authentication_pingActive_result.prototype.write = function(output) {
  output.writeStructBegin('Authentication_pingActive_result');
  if (this.success !== null && this.success !== undefined) {
    output.writeFieldBegin('success', Thrift.Type.BOOL, 0);
    output.writeBool(this.success);
    output.writeFieldEnd();
  }
  output.writeFieldStop();
  output.writeStructEnd();
  return;
};

Authentication_login_args = function(args) {
  this.user = null;
  if (args) {
    if (args.user !== undefined) {
      this.user = args.user;
    }
  }
};
Authentication_login_args.prototype = {};
Authentication_login_args.prototype.read = function(input) {
  input.readStructBegin();
  while (true)
  {
    var ret = input.readFieldBegin();
    var fname = ret.fname;
    var ftype = ret.ftype;
    var fid = ret.fid;
    if (ftype == Thrift.Type.STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
      if (ftype == Thrift.Type.STRUCT) {
        this.user = new User();
        this.user.read(input);
      } else {
        input.skip(ftype);
      }
      break;
      case 0:
        input.skip(ftype);
        break;
      default:
        input.skip(ftype);
    }
    input.readFieldEnd();
  }
  input.readStructEnd();
  return;
};

Authentication_login_args.prototype.write = function(output) {
  output.writeStructBegin('Authentication_login_args');
  if (this.user !== null && this.user !== undefined) {
    output.writeFieldBegin('user', Thrift.Type.STRUCT, 1);
    this.user.write(output);
    output.writeFieldEnd();
  }
  output.writeFieldStop();
  output.writeStructEnd();
  return;
};

Authentication_login_result = function(args) {
  this.success = null;
  this.ouch = null;
  if (args instanceof InvalidOperation) {
    this.ouch = args;
    return;
  }
  if (args) {
    if (args.success !== undefined) {
      this.success = args.success;
    }
    if (args.ouch !== undefined) {
      this.ouch = args.ouch;
    }
  }
};
Authentication_login_result.prototype = {};
Authentication_login_result.prototype.read = function(input) {
  input.readStructBegin();
  while (true)
  {
    var ret = input.readFieldBegin();
    var fname = ret.fname;
    var ftype = ret.ftype;
    var fid = ret.fid;
    if (ftype == Thrift.Type.STOP) {
      break;
    }
    switch (fid)
    {
      case 0:
      if (ftype == Thrift.Type.BOOL) {
        this.success = input.readBool().value;
      } else {
        input.skip(ftype);
      }
      break;
      case 1:
      if (ftype == Thrift.Type.STRUCT) {
        this.ouch = new InvalidOperation();
        this.ouch.read(input);
      } else {
        input.skip(ftype);
      }
      break;
      default:
        input.skip(ftype);
    }
    input.readFieldEnd();
  }
  input.readStructEnd();
  return;
};

Authentication_login_result.prototype.write = function(output) {
  output.writeStructBegin('Authentication_login_result');
  if (this.success !== null && this.success !== undefined) {
    output.writeFieldBegin('success', Thrift.Type.BOOL, 0);
    output.writeBool(this.success);
    output.writeFieldEnd();
  }
  if (this.ouch !== null && this.ouch !== undefined) {
    output.writeFieldBegin('ouch', Thrift.Type.STRUCT, 1);
    this.ouch.write(output);
    output.writeFieldEnd();
  }
  output.writeFieldStop();
  output.writeStructEnd();
  return;
};

Authentication_logout_args = function(args) {
  this.user = null;
  if (args) {
    if (args.user !== undefined) {
      this.user = args.user;
    }
  }
};
Authentication_logout_args.prototype = {};
Authentication_logout_args.prototype.read = function(input) {
  input.readStructBegin();
  while (true)
  {
    var ret = input.readFieldBegin();
    var fname = ret.fname;
    var ftype = ret.ftype;
    var fid = ret.fid;
    if (ftype == Thrift.Type.STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
      if (ftype == Thrift.Type.STRUCT) {
        this.user = new User();
        this.user.read(input);
      } else {
        input.skip(ftype);
      }
      break;
      case 0:
        input.skip(ftype);
        break;
      default:
        input.skip(ftype);
    }
    input.readFieldEnd();
  }
  input.readStructEnd();
  return;
};

Authentication_logout_args.prototype.write = function(output) {
  output.writeStructBegin('Authentication_logout_args');
  if (this.user !== null && this.user !== undefined) {
    output.writeFieldBegin('user', Thrift.Type.STRUCT, 1);
    this.user.write(output);
    output.writeFieldEnd();
  }
  output.writeFieldStop();
  output.writeStructEnd();
  return;
};

Authentication_logout_result = function(args) {
  this.success = null;
  this.ouch = null;
  if (args instanceof InvalidOperation) {
    this.ouch = args;
    return;
  }
  if (args) {
    if (args.success !== undefined) {
      this.success = args.success;
    }
    if (args.ouch !== undefined) {
      this.ouch = args.ouch;
    }
  }
};
Authentication_logout_result.prototype = {};
Authentication_logout_result.prototype.read = function(input) {
  input.readStructBegin();
  while (true)
  {
    var ret = input.readFieldBegin();
    var fname = ret.fname;
    var ftype = ret.ftype;
    var fid = ret.fid;
    if (ftype == Thrift.Type.STOP) {
      break;
    }
    switch (fid)
    {
      case 0:
      if (ftype == Thrift.Type.BOOL) {
        this.success = input.readBool().value;
      } else {
        input.skip(ftype);
      }
      break;
      case 1:
      if (ftype == Thrift.Type.STRUCT) {
        this.ouch = new InvalidOperation();
        this.ouch.read(input);
      } else {
        input.skip(ftype);
      }
      break;
      default:
        input.skip(ftype);
    }
    input.readFieldEnd();
  }
  input.readStructEnd();
  return;
};

Authentication_logout_result.prototype.write = function(output) {
  output.writeStructBegin('Authentication_logout_result');
  if (this.success !== null && this.success !== undefined) {
    output.writeFieldBegin('success', Thrift.Type.BOOL, 0);
    output.writeBool(this.success);
    output.writeFieldEnd();
  }
  if (this.ouch !== null && this.ouch !== undefined) {
    output.writeFieldBegin('ouch', Thrift.Type.STRUCT, 1);
    this.ouch.write(output);
    output.writeFieldEnd();
  }
  output.writeFieldStop();
  output.writeStructEnd();
  return;
};

AuthenticationClient = function(input, output) {
    this.input = input;
    this.output = (!output) ? input : output;
    this.seqid = 0;
};
AuthenticationClient.prototype = {};
AuthenticationClient.prototype.pingActive = function(genNum) {
  this.send_pingActive(genNum);
  return this.recv_pingActive();
};

AuthenticationClient.prototype.send_pingActive = function(genNum) {
  this.output.writeMessageBegin('pingActive', Thrift.MessageType.CALL, this.seqid);
  var args = new Authentication_pingActive_args();
  args.genNum = genNum;
  args.write(this.output);
  this.output.writeMessageEnd();
  return this.output.getTransport().flush();
};

AuthenticationClient.prototype.recv_pingActive = function() {
  var ret = this.input.readMessageBegin();
  var fname = ret.fname;
  var mtype = ret.mtype;
  var rseqid = ret.rseqid;
  if (mtype == Thrift.MessageType.EXCEPTION) {
    var x = new Thrift.TApplicationException();
    x.read(this.input);
    this.input.readMessageEnd();
    throw x;
  }
  var result = new Authentication_pingActive_result();
  result.read(this.input);
  this.input.readMessageEnd();

  if (null !== result.success) {
    return result.success;
  }
  throw 'pingActive failed: unknown result';
};
AuthenticationClient.prototype.login = function(user) {
  this.send_login(user);
  return this.recv_login();
};

AuthenticationClient.prototype.send_login = function(user) {
  this.output.writeMessageBegin('login', Thrift.MessageType.CALL, this.seqid);
  var args = new Authentication_login_args();
  args.user = user;
  args.write(this.output);
  this.output.writeMessageEnd();
  return this.output.getTransport().flush();
};

AuthenticationClient.prototype.recv_login = function() {
  var ret = this.input.readMessageBegin();
  var fname = ret.fname;
  var mtype = ret.mtype;
  var rseqid = ret.rseqid;
  if (mtype == Thrift.MessageType.EXCEPTION) {
    var x = new Thrift.TApplicationException();
    x.read(this.input);
    this.input.readMessageEnd();
    throw x;
  }
  var result = new Authentication_login_result();
  result.read(this.input);
  this.input.readMessageEnd();

  if (null !== result.ouch) {
    throw result.ouch;
  }
  if (null !== result.success) {
    return result.success;
  }
  throw 'login failed: unknown result';
};
AuthenticationClient.prototype.logout = function(user) {
  this.send_logout(user);
  return this.recv_logout();
};

AuthenticationClient.prototype.send_logout = function(user) {
  this.output.writeMessageBegin('logout', Thrift.MessageType.CALL, this.seqid);
  var args = new Authentication_logout_args();
  args.user = user;
  args.write(this.output);
  this.output.writeMessageEnd();
  return this.output.getTransport().flush();
};

AuthenticationClient.prototype.recv_logout = function() {
  var ret = this.input.readMessageBegin();
  var fname = ret.fname;
  var mtype = ret.mtype;
  var rseqid = ret.rseqid;
  if (mtype == Thrift.MessageType.EXCEPTION) {
    var x = new Thrift.TApplicationException();
    x.read(this.input);
    this.input.readMessageEnd();
    throw x;
  }
  var result = new Authentication_logout_result();
  result.read(this.input);
  this.input.readMessageEnd();

  if (null !== result.ouch) {
    throw result.ouch;
  }
  if (null !== result.success) {
    return result.success;
  }
  throw 'logout failed: unknown result';
};

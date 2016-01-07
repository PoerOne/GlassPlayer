// conn_xcast.h
//
// Server connector for Icecast/Shoutcast streams.
//
//   (C) Copyright 2014-2016 Fred Gleason <fredg@paravelsystems.com>
//
//   This program is free software; you can redistribute it and/or modify
//   it under the terms of the GNU General Public License version 2 as
//   published by the Free Software Foundation.
//
//   This program is distributed in the hope that it will be useful,
//   but WITHOUT ANY WARRANTY; without even the implied warranty of
//   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//   GNU General Public License for more details.
//
//   You should have received a copy of the GNU General Public
//   License along with this program; if not, write to the Free Software
//   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
//

#ifndef CONN_XCAST_H
#define CONN_XCAST_H

#include <QTcpSocket>

#include "connector.h"

class XCast : public Connector
{
  Q_OBJECT;
 public:
  XCast(QObject *parent=0);
  ~XCast();
  Connector::ServerType serverType() const;

 protected:
  void connectToHostConnector(const QString &hostname,uint16_t port);
  void disconnectFromHostConnector();

 private slots:
  void connectedData();
  void readyReadData();
  void errorData(QAbstractSocket::SocketError err);

 private:
  void SendHeader(const QString &str);
  void ProcessHeader(const QString &str);
  QString xcast_header;
  bool xcast_header_active;
  QTcpSocket *xcast_socket;
  int xcast_result_code;
  int xcast_metadata_interval;
  int xcast_metadata_istate;
  QString xcast_metadata_string;
};


#endif  // CONN_XCAST_H

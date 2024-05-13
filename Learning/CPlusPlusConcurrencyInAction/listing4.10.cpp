/*
 * File: listing4.10.cpp Handling multiple connections from a single thread using promises
 * Project: CPlusPlusConcurrencyInAction
 * File Created: Tuesday, 23rd August 2022 3:50:17 pm
 * Author: tung.dao (thanhtungpfiev@gmail.com)
 * -----
 */
#include <iostream>
#include <future>

using namespace std;

class connection_set
{
};

void process_connections(connection_set &connections)
{
    while (!done(connections))
    {
        for (connection_iterator connection = connections.begin(); connection != connections.end(); ++connection)
        {
            if (connection->has_incoming_data())
            {
                data_packet data = connection->incoming();
                std::promise<payload_type> &p = connection->get_promise(data.id);
                p.set_value(data.payload);
            }

            if (connection->has_outgoing_data())
            {
                outgoing_packet data = connection->top_of_outgoing_queue();
                connection->send_data(data.payload);
                data.promise.set_value(true);
            }
        }
    }
}

int main(int argc, char **argv)
{
    cout << "Hello World" << endl;
    return 0;
}
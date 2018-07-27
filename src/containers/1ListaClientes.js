/* import _ from "lodash";
import React, { Component } from "react";
import { connect } from "react-redux";
import { fetchClientes } from "../actions/index";
import { Link } from "react-router-dom";


class ListaClientes extends Component {
    componentWillMount() {
        this.props.fetchClientes();
    }

    renderClientes() {
        return _.map(this.props.clientes, (cliente => {
            return (
                <li className="list-group-item" key={post.id}>
                    <Link to={"/posts/" + post.id}>
                        <span className="pull-xs-right">{post.categories}</span>
                        <strong>{post.title}</strong>
                    </Link>
                </li>
            );
        });
    }

render() {
    return (
        <div>
            <table className="table">
                <thead className="thead-light">
                    <tr>
                        <th scope="col">ID</th>
                        <th scope="col">Nome</th>
                        <th scope="col">Endereço</th>
                        <th scope="col">Telefone</th>
                        <th scope="col">Data de nascimento</th>
                    </tr>
                </thead>
                <tbody>
                    <tr>
                        <th scope="row">1</th>
                        <td>Cristiano Coelho</td>
                        <td>
                            Rua Pouso Alegre, 235, bairro Capelinha, Betim-MG
                            CEP: 32678-738
                        </td>
                        <td>(31)98587-7928</td>
                        <td>15/03/1994</td>
                    </tr>
                </tbody>
            </table>
        </div>
    );
};

export default ListaClientes;
 */
